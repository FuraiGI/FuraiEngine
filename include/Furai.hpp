#ifndef FURAI_HPP
#define FURAI_HPP

#include <iostream>
#include <stdexcept>

#define MAIN_LOOP(obj)  while(!obj.WindowShouldClose())

// graphics
#include <graphic/graphics.hpp>
#include <graphic/Shader.hpp>
#include <graphic/Mesh.hpp>
#include <graphic/shape/shape.hpp>
#include <graphic/shape/polygon.hpp>
#include <paths.hpp>

// input
#include <input/input.hpp>

#endif // FURAI_HPP