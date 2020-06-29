#ifndef JDS_MAP_H_
#define JDS_MAP_H_

#include "jlist.h"

namespace jds 
{
	template<typename K, typename V>
	struct jmap_entry
	{
		K key;
		V value;
	};

	template<typename K, typename V>
	class jmap : public jlist<jmap_entry<K, V>*>
	{
	public:
		jmap();
		jmap(bool (*f_com)(void* e1, void* e2), bool (*k_com)(const K& k1, const K& k2), bool (*v_com)(const V& v1, const V& v2));
		~jmap();

		void insert(const K& key, const V& value);
		void erase(jiterator<jmap_entry<K, V>*>* it);
		jiterator<jmap_entry<K, V>*>* find(const K& key);
		bool contains(const K& key);

	private:
		bool (*compare)(jmap_entry<K, V>* e1, jmap_entry<K, V>* e2);
		bool (*key_compare)(const K& k1, const K& k2);
		bool (*value_compare)(const V& v1, const V& v2);
	};

}

#endif // !JDS_MAP_H_
