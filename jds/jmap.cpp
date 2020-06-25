#include "jmap.h"

namespace jds {

	template<typename K, typename V>
	jmap<K, V>::jmap()
	{

	}

	template<typename K, typename V>
	jmap<K, V>::jmap(bool (*f_com)(void* e1, void* e2), bool (*k_com)(const K& k1, const K& k2), bool (*v_com)(const V& v1, const V& v2))
	{
		this->compare = f_com;
		this->key_compare = k_com;
		this->value_compare = v_com;
	}

	template<typename K, typename V>
	jmap<K, V>::~jmap()
	{

	}

	template<typename K, typename V>
	void jmap<K, V>::insert(const K& key, const V& value)
	{
		jmap_entry<K, V>* entry = new jmap_entry<K, V>(key, value);
		this->push_front(entry);
	}

	template<typename K, typename V>
	void jmap<K, V>::erase(jiterator<jmap_entry<K, V>*>* it)
	{
		this->remove(it);
	}
	template<typename K, typename V>
	jiterator<jmap_entry<K, V>*>* jmap<K, V>::find(const K& key)
	{
		jiterator* it = this->begin();
		jmap_entry<K, V>* entry = nullptr;
		while (it)
		{
			entry = (jmap_entry<K, V>*) it;
			if (this->key_compare(entry->key, key))
			{
				return it;
			}
			it++;
		}

		return nullptr;
	}

	template<typename K, typename V>
	bool jmap<K, V>::contains(const K& key)
	{
		jiterator* it = this->begin();
		jmap_entry<K, V>* entry = nullptr;
		while (it)
		{
			entry = (jmap_entry<K, V>*) it;
			if (this->key_compare(entry->key, key))
			{
				return true;
			}
			it++;
		}

		return false;
	}
}