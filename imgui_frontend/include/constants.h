//---------------------------------------------------------------------------------------------------------------------------------------
//
//
// Author: Ciara Giles-Doran <gciara@student.ethz.ch>
// Last updated: 
//---------------------------------------------------------------------------------------------------------------------------------------


// Serial port constants
#define PORT_NAME                   "/dev/ttyACM0"
                                    //"/dev/cu.usbmodem105688601";  
                                    //"cu.usbmodem105688601";           ALIVE non soldered board
                                    //"/cu.usbmodem105661701";          ALIVE BOARD

// AER-related constants
#define AER_NO_CORES                2
#define AER_NO_SYNAPSE_TYPES        4
#define AER_NO_NEURONS              4
#define AER_NO_NMDA_SYNAPSES        40
#define AER_NO_GABAa_SYNAPSES       2
#define AER_NO_GABAb_SYNAPSES       16
#define AER_NO_AMPA_SYNAPSES        6
#define AER_NO_AMPA_SYNAPSES_NN     3       // 3 AMPA+ and 3 AMPA-

#define AER_CORE_SHIFT              8
#define AER_SYNAPSE_TYPE_SHIFT      6
#define AER_NEURON_SHIFT            4
#define AER_NN_GABAb_BITS_4_5       1
#define AER_GABAa_BITS_1_2_3        7
#define AER_AMPA_SHIFT              3
#define AER_PACKET_SIZE             9

// DAC-related constants
#define DAC_BIASFILE                "data/BiasValues_DAC.csv"
#define DAC_CHANNELS_USED           11
#define DAC_COMMAND_WRITE_UPDATE    48      // 0011 0000
#define DAC_MAX_VOLTAGE             1800    // mV

// BIASGEN-related constants
#define BIASGEN_BIASFILE            "data/BiasValues_BIASGEN.csv"
#define BIASGEN_CHANNELS            54
#define BIASGEN_CATEGORIES          9
#define BIASGEN_MAX_CURRENT         1.9     // uA
#define BIASGEN_NO_MASTER_CURRENTS  6
#define BIASGEN_MULTIPL_FACTOR      256
#define BIASGEN_COURSE_BIAS_SHIFT   9
#define BIASGEN_FINE_BIAS_SHIFT     1
#define BIASGEN_PACKET_SIZE         12

// GUI-related constants
#define BUTTON_HEIGHT               20
#define BUTTON_UPDATE_WIDTH         100
#define BUTTON_AER_WIDTH            285
#define WINDOW_HEIGHT               800
#define WINDOW_WIDTH                1100
#define CLEAR_COLOUR_X              0.45f
#define CLEAR_COLOUR_Y              0.55f
#define CLEAR_COLOUR_Z              0.60f
#define CLEAR_COLOUR_W              1.00f