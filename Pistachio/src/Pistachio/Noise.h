#pragma once

namespace Pistachio {

	class PISTACHIO_API Noise
	{
	public:
		static std::vector<float> Simplex2D(unsigned int width, unsigned int height);
	};
}