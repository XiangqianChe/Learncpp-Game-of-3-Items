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

std::string_view getItemsSigular(Items::Type type)
{
    switch (type)
    {
    case Items::health_potion: return "health_potion";
    case Items::torch: return "torch";
    case Items::arrow: return "arrow";
    default: return "???";
    }
}

std::string_view getItemsPlural(Items::Type type)
{
    switch (type)
    {
    case Items::health_potion: return "health_potions";
    case Items::torch: return "torches";
    case Items::arrow: return "arrows";
    default: return "???";
    }
}

void printInventoryItem(const std::vector<int>& inventory, Items::Type type)
{
    bool plural{ inventory[type] != 1 };
    std::cout << "You have " << inventory[type] << ' '
        << (plural ? getItemsPlural(type) : getItemsSigular(type)) << '\n';
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
    assert(std::size(inventory) == Items::max_items);
    for (int index{}; index < Items::max_items; ++index)
        printInventoryItem(inventory, static_cast<Items::Type>(index));
    std::cout << "You have " << countItems(inventory) << " total items\n";

    return 0;
}