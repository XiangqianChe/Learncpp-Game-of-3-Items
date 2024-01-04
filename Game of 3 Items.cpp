#include <iostream>
#include <vector>
#include <cassert>

namespace Items
{
    enum Type
    {
        health_potion,
        torch,
        arrow,
        max_items,
    };
}

int countItems(const std::vector<int>& inventory)
{
    int count{};
    for (auto e : inventory)
        count += e;
    return count;
}


int main()
{
    std::vector inventory{ 1, 5, 10 };
    assert(inventory.size() == Items::max_items);
    std::cout << "You have " << countItems(inventory) << " total items\n";

    return 0;
}