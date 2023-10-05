class MyHashMap
{
private:
    vector<list<pair<int, int>>> data;
    const int size = 10000;

public:
    MyHashMap()
    {
        data.resize(size);
    }

    void put(int key, int value)
    {
        int index = key % size;
        for (auto it = data[index].begin(); it != data[index].end(); it++)
        {
            if (it->first == key)
            {
                it->second = value;
                return;
            }
        }
        data[index].push_back(make_pair(key, value));
    }

    int get(int key)
    {
        int index = key % size;
        for (auto it = data[index].begin(); it != data[index].end(); it++)
        {
            if (it->first == key)
            {
                return it->second;
            }
        }
        return -1;
    }

    void remove(int key)
    {
        int index = key % size;
        for (auto it = data[index].begin(); it != data[index].end(); it++)
        {
            if (it->first == key)
            {
                data[index].erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = MyHashMap();
 * obj.put(key,value);
 * int param2 = obj.get(key);
 * obj.remove(key);
 */