#pragma once

#include "Renderer/FractalInterface.h"

/*
This class contains the mathematical implementation of the mandelbrot set.
For more details about this fractal, see: https://en.wikipedia.org/wiki/Mandelbrot_set
*/

class Mandelbrot : public FractalInterface
{
public:
	double Evaluate(double real, double imaginary)
	{
		// At a high level, compute (zn+1 = zn ^ 2 + c) until zn+1 has a magnitude > 2 or until max iterations
		double zn_real = 0, zn_imag = 0;
		double znplus1_real = 0, znplus1_imag = 0;
		for (double i = 0; i < maxIterations_; i++) {
			// Calculate zn+1 as zn ^ 2 + c
			znplus1_real = (zn_real * zn_real) - (zn_imag * zn_imag) + real;
			znplus1_imag = 2 * zn_real * zn_imag + imaginary;

			// Set zn equal to zn+1
			zn_real = znplus1_real;
			zn_imag = znplus1_imag;

			// Check if the magnitude of zn is greater than 2
			// Which is equal to if the square magnitude is greater than 4 (more efficient)
			if ((zn_real * zn_real) + (zn_imag * zn_imag) > 4) {
				return i / maxIterations_;
			}
		}

		// If after maxIterations the point did not return, it is in the set
		return 1;
	}
};