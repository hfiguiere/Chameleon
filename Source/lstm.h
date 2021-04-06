/*
  ==============================================================================

  lstm

  ==============================================================================
*/

#include "ModelLoader.h"
#include "NumCpp.hpp"

#include <algorithm>

class lstm
{
    public:
        lstm();

        // Math and vector operations
        float tanh(float x);
        float sigmoid(float x);

        // Layers
        void lstm_layer();
        void dense_layer();

        void process(const float* inData, float* outData, int numSamples);

        void setParams( int hidden_size, 
                        nc::NdArray<float> lstm_weights_ih_nc,
                        nc::NdArray<float> lstm_weights_hh_nc,
                        nc::NdArray<float> lstm_bias_nc,
                        nc::NdArray<float> dense_bias_nc,
                        nc::NdArray<float> dense_weights_nc);

        // Data processing
        nc::NdArray<float> input = nc::zeros<float>(nc::Shape(1, 1));
        std::vector<float> new_buffer;
        std::vector<float> old_buffer;
        std::vector<std::vector<float>> data;

        // Network Parameters
        int HS = 20;

        // LSTM calc
        nc::NdArray<float> gates = nc::zeros<float>(1, HS * 4);
        nc::NdArray<float> h_t = nc::zeros<float>(1, HS);
        nc::NdArray<float> c_t = nc::zeros<float>(1, HS);

        // Loaded Model Weights and Biases
        nc::NdArray<float> lstm_weights_ih;
        nc::NdArray<float> lstm_weights_hh;
        nc::NdArray<float> lstm_bias;

        nc::NdArray<float> dense_bias;
        nc::NdArray<float> dense_weights;

        // Layer in/out
        nc::NdArray<float> xt = nc::zeros<float>(1,1);
        nc::NdArray<float> lstm_out;
        nc::NdArray<float> dense_out;
 
    private:

};

