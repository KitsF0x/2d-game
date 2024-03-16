#include "AManager.hpp"

void kf::AManager::add(std::shared_ptr<IManageable> entity)
{
    entities.push_back(entity);
}

void kf::AManager::remove(std::shared_ptr<IManageable> entity)
{
    entities.erase(std::remove(entities.begin(), entities.end(), entity), entities.end());
}

std::size_t kf::AManager::size() const
{
    return entities.size();
}
