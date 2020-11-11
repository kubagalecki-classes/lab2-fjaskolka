#pragma once

#include "Resource.hpp"


class ResourceManager {

  private:
    Resource* m_resource;

  public:
    ResourceManager(); // konstruktor
    ~ResourceManager(); // destruktor
    ResourceManager(const ResourceManager& a); // konstruktor kopiujący
    ResourceManager& operator=(const ResourceManager& a); // kopiujacy operator przypisania
    ResourceManager(ResourceManager&& a); // kontruktor przenoszacy

    double get() { return m_resource->get(); }
};

ResourceManager::ResourceManager()// konstruktor
{
  m_resource = new Resource;
}

ResourceManager::~ResourceManager()// destruktor
{
  delete m_resource;
}

ResourceManager::ResourceManager(const ResourceManager& a)// konstruktor kopiujący
{
  m_resource = new Resource(*(a.m_resource));
}

ResourceManager& ResourceManager::operator=(const ResourceManager& a); // kopiujacy operator przypisania
{
  if(&a == this)
  {
    return *this;
  }
  delete m_resource;
  m_resource = new Resource(*(a.m_resource));
  return *this;
}

ResourceManager::ResourceManager(ResourceManager&& a) // konstruktor przenoszący
{
  m_resource = a.m_resource;
  a.m_resource = nullptr;
}