#ifndef JDS_JHASH_TABLE_H_
#define JDS_JHASH_TABLE_H_

#include "jlist.h"
#include "jmap.h"

namespace jds
{
	template<typename K, typename V>
	class jhash_table
	{
	public:
		jhash_table();
		jhash_table(size_t BUCKET, void (*_hash_func)(const K& key), bool (*_key_compare)(const K& k1, const K& k2));
		~jhash_table();

		void insert(jmap_entry<K, V>* entry);
		void erase(jmap_entry<K, V>* entry);
		jmap_entry<K, V>* find(const K& key);
		size_t size();


	private:
		size_t bucket;
		size_t num_entry;
		jlist<jmap_entry<K, V>*>* entry_list;
		void (*hash_func)(const K& key);
		bool (*key_compare)(const K& k1, const K& k2);
	};
}

#endif // !JDS_JHASH_TABLE_H_
