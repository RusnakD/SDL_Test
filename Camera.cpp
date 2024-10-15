#include "Camera.h"

Camera::Camera()
{
    // The dimensions of the rectangle
    deadZone.w = scrWidth - (2 * deadZoneMargin);
    deadZone.h = scrHeight - (2 * deadZoneMargin);

    // Fixed position in the middle of the screen
    deadZone.x = deadZoneMargin;
    deadZone.y = deadZoneMargin;
}

Camera::~Camera()
{
}

void Camera::move(int diffX, int diffY)
{
    offset.x += diffX;
    offset.y += diffY;
}

void Camera::setRenderer(SDL_Renderer* argRen)
{
    ren = argRen;
}

// For testing purposes only, I want to be able to see the zone size
void Camera::drawDeadZone()
{
    SDL_SetRenderDrawBlendMode(ren, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(ren, 255, 255, 0, 20);           //Yellow rect with transparency
    SDL_RenderFillRect(ren, &deadZone);
}

SDL_Point Camera::getOffset()
{
    return offset;
}

SDL_Rect Camera::getZoneRect()
{
    return deadZone;
}
