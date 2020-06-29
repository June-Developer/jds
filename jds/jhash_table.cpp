#include "jhash_table.h"

namespace jds
{
	template<typename K, typename V>
	jhash_table<K, V>::jhash_table()
	{

	}
	template<typename K, typename V>
	jhash_table<K, V>::jhash_table(size_t BUCKET, void (*_hash_func)(const K& key), bool (*_key_compare)(const K& k1, const K& k2))
	{
		this->bucket = BUCKET;
		this->hash_func = _hash_func;
		this->key_compare = _key_compare;
		this->entry_list = new jlist<jmap_entry<K, V>*>[BUCKET];
	}
	template<typename K, typename V>
	jhash_table<K, V>::~jhash_table()
	{
		return NULL;
	}

	template<typename K, typename V>
	void jhash_table<K, V>::insert(jmap_entry<K, V>* entry)
	{
		int index = this->hash_func(entry->key);
		this->entry_list[index].push_back(entry);
	}

	template<typename K, typename V>
	void jhash_table<K, V>::erase(jmap_entry<K, V>* entry)
	{
		int index = this->hash_func(entry->key);
		this->entry_list[index].remove(entry);
		return;
	}

	template<typename K, typename V>
	jmap_entry<K, V>* jhash_table<K, V>::find(const K& key)
	{
		int index = this->hash_func(key);
		jiterator* it = this->entry_list[index].begin();
		whiel(it)
		{
			if (((jmap_entry<K, V>*) it).key == key)
			{
				return it;
			}
			it++;
		}
		return NULL;
	}

	template<typename K, typename V>
	size_t jhash_table<K, V>::size()
	{
		return this->num_entry;
	}
}