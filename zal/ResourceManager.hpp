#pragma once

#include "Resource.hpp"


class ResourceManager {

  private:
    Resource* m_resource;

  public:
    ResourceManager(); // utwórz obiekt resource
    {
      m_resource = new Resource;
    }
    ~ResourceManager(); // zwolnij obiekt resource
    {
      delete m_resource;
    }
    ResourceManager(const ResourceManager& a); // konstruktor kopiujący
    {
      m_resource = new Resource(*(a.m_resource));
    }
    ResourceManager& operator=(ResourceManager&& a); // operator przypisania
    {
      if(&a == this)
      {
        return *this;
      }
      delete m_resource;
      m_resource = new Resource(*(a.m_resource));
      return *this;
    }
    ResourceManager(ResourceManager&& a); // konstruktor przenoszący
    {
      m_resource = a.m_resource;
      a.m_resource = nullptr;   
    }
    double get()
    {
      return m_resource->get();
    }
};
