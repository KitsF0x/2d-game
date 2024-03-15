#include "Camera.hpp"

const float kf::Camera::ZOOM_FACTOR{0.91f};

kf::Camera::Camera(sf::RenderWindow &window) : window(window)
{
    view.setCenter(sf::Vector2f{0.0f, 0.0f});
    view.setSize(static_cast<float>(window.getSize().x), static_cast<float>(window.getSize().y));
    window.setView(view);
}

void kf::Camera::update(const sf::Vector2f &center)
{
    view.setCenter(center);
    window.setView(view);
}

void kf::Camera::zoomIn()
{
    view.zoom(ZOOM_FACTOR);
}

void kf::Camera::zoomOut()
{
    view.zoom(1.0f / ZOOM_FACTOR);
}
