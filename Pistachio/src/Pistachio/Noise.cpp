#include "pacopch.h"
#include "Noise.h"

#include "FastNoise/FastNoise.h"

namespace Pistachio {

	std::vector<float> Noise::Simplex2D(unsigned int width, unsigned int height)
	{
		auto fnSimplex = FastNoise::New<FastNoise::Simplex>();

		std::vector<float> noiseOutput(width * height);

		fnSimplex->GenUniformGrid2D(noiseOutput.data(), 0, 0, width, height, 0.2f, 1337);

		return noiseOutput;
	}
}