#ifndef LAYERS_H
#define LAYERS_H
#pragma once

#include <cstddef>
#include <vector>
#include <print>
#include "Utility/Utility.h"
#include "MLP/Neuron.h"

namespace MLP::Layers 
{
	class Matrice
	{
	private:

	public:
		Matrice()
		{ }

		float findConnectionWeight(const MLP::Neuron::Neuron& inputNeuron, const MLP::Neuron::Neuron& outputNeuron)
		{
			return 0.0f;
		}
	};

	struct Layer
	{
		std::vector<MLP::Neuron::Neuron> neurons;
		std::size_t size = neurons.size();
		Matrice connectionWeights;
		Layer* prevLayer = nullptr;

		void activationLayer();
	};
}
#endif