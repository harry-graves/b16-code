#ifndef __hash__
#define __hash__

#include <cassert>
#include <iostream>
#include <limits>
#include <vector>

#include "../part-1/list.hpp"

template <typename K, typename V, typename H> class HashTable
{
  public:
    HashTable(size_t num_chains) : _table{num_chains} {}

    void insert(const K &key, const V &value)
    {
        size_t slot = _get_slot(key);
        Node<KeyValuePair> *node = _find_key(slot, key);
        if (!node) {
            list_insert_after(&_table[slot], {key, value});
        } else {
            node->next->value.value = value;
        }
    }

    V *get(const K &key)
    {
        size_t slot = _get_slot(key);
        Node<KeyValuePair> *node = _find_key(slot, key);
        if (!node) { return nullptr; }
        return &node->next->value.value;
    }

    void print(bool details = false) const
    {
        size_t min = std::numeric_limits<size_t>::max(), max = 0, average = 0;
        for (size_t slot = 0; slot < _table.size(); ++slot) {
            if (details) { std::cout << "Slot " << slot << " contains"; }
            size_t count = 0;
            for (Node<KeyValuePair> *node = _table[slot].next.get(); node;
                 node = node->next.get()) {
                if (details) { std::cout << " '" << node->value.key << '\''; }
                count++;
            }
            if (details) { std::cout << " (" << count << ")\n"; }
            max = std::max(count, max);
            min = std::min(count, min);
            average += count;
        }
        std::cout << "Slot sizes: min: " << min;
        std::cout << ", max: " << max;
        std::cout << ", average: " << float(average) / _table.size() << '\n';
    }

    uint32_t hash(const std::string& str, const uint32_t m)
    {
        // Initialize the hash value
        uint64_t hashValue = 0;

        // Compute the hash value using the division method
        for (char c : str)
        {
            // Update the hash value using modular arithmetic
            hashValue = (hashValue * 256 + static_cast<uint8_t>(c)) % m;
        }

        // Return the computed hash value
        return static_cast<uint32_t>(hashValue);
    }

  private:
    struct KeyValuePair {
        K key;
        V value;
    };

    std::vector<Node<KeyValuePair>> _table;

    size_t _get_slot(const K &key) const { return H{}(key) % _table.size(); }

    Node<KeyValuePair> *_find_key(size_t slot, const K &key)
    {
        auto match = [&](const KeyValuePair &pair) { return pair.key == key; };
        return list_find_predecessor(&_table[slot], match);
    }
};

#endif // __hash__