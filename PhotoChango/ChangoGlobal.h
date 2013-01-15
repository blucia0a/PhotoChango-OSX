#ifndef _CHANGO_GLOBAL_H_
#define _CHANGO_GLOBAL_H_

#include "tones.h"

#define NUM_WAVES 100
static const char  * WINDOW_NAME  = "PhotoChango - Brandon Lucia 2011 - http://cs.washington.edu/homes/blucia0a - 'q' to quit";
int handleKey();

#define NUM_TONES_TOTAL 88

static float ToneList[] = { A, Asharp, B, C1, Csharp1, D1, Dsharp1, E1, F1, Fsharp1, G1, Gsharp1, A1, Asharp1, B1, C2, Csharp2, D2, Dsharp2, E2, F2, Fsharp2, G2, Gsharp2, A2, Asharp2, B2, C3, Csharp3, D3, Dsharp3, E3, F3, Fsharp3, G3, Gsharp3, A3, Asharp3, B3, C4, Csharp4, D4, Dsharp4, E4, F4, Fsharp4, G4, Gsharp4, A4, Asharp4, B4, C5, Csharp5, D5, Dsharp5, E5, F5, Fsharp5, G5, Gsharp5, A5, Asharp5, B5, C6, Csharp6, D6, Dsharp6, E6, F6, Fsharp6, G6, Gsharp6, A6, Asharp6, B6, C7, Csharp7, D7, Dsharp7, E7, F7, Fsharp7, G7, Gsharp7, A7, Asharp7, B7, C8};

/*
static float tones[NUM_WAVES] = { Asharp3, Asharp3, C3, C3, D3, D3, Dsharp3, Dsharp3,  
                                  Asharp3, Asharp3, C3, C3, D3, D3, Dsharp3, Dsharp3,  
	                              
	                          F3,      F3,      G3, G3, A4, A4, Asharp3, Asharp3, Csharp3, Csharp3, C4, C4,
	                              F3, F3, G3, G3, A4, A4, Asharp3, Asharp3, Csharp3, Csharp3, C4, C4,
	                      
				      D4, D4, Dsharp4, Dsharp4, F4, F4, G4, G4, A5, A5,
	                              D4, D4, Dsharp4, Dsharp4, F4, F4, G4, G4, A5, A5,
	
	                              Asharp5, Asharp5, C5, C5, D5, D5, Dsharp5, Dsharp5, F5, F5,
	                              Asharp5, Asharp5, C5, C5, D5, D5, Dsharp5, Dsharp5, F5, F5,
	
	                              G5, G5, A6, A6, Asharp6, Asharp6, C6, C6, D6, D6, 
	                              G5, G5, A6, A6, Asharp6, Asharp6, C6, C6, D6, D6};*/
//F# G# A# B C D D# F

/*static float tones[NUM_WAVES] = {  C3,      C3,      Csharp3, Csharp3, D3, D3, Dsharp3, Dsharp3, G3, G3,
                                   C3,      C3,      Csharp3, Csharp3, D3, D3, Dsharp3, Dsharp3, G3, G3, 
	                             
                                   Gsharp3, Gsharp3, A3,      A3,      C4, C4, Csharp4, Csharp4, D4, D4,
                                   Gsharp3, Gsharp3, A3,      A3,      C4, C4, Csharp4, Csharp4, D4, D4,

                                   Dsharp4, Dsharp4, F4,      F4,      G4, G4, Gsharp4, Gsharp4, A4, A4,
                                   Dsharp4, Dsharp4, F4,      F4,      G4, G4, Gsharp4, Gsharp4, A4, A4,

                                   C5,      C5,      Csharp5, Csharp5, D5, D5, Dsharp5, Dsharp5, F5, F5,
                                   C5,      C5,      Csharp5, Csharp5, D5, D5, Dsharp5, Dsharp5, F5, F5,

                                   G5,      G5,      Gsharp5, Gsharp5, A5, A5, C5,      C5,      Gsharp6, Gsharp6,
                                   G5,      G5,      Gsharp5, Gsharp5, A5, A5, C5,      C5,      Gsharp6, Gsharp6};*/


static float tones[NUM_WAVES] = {  C3,      C3,      Fsharp3, Fsharp3, D3, D3, Dsharp3, Dsharp3, Gsharp3, Gsharp3,
                                   C3,      C3,      Fsharp3, Fsharp3, D3, D3, Dsharp3, Dsharp3, Gsharp3, Gsharp3,
    
                                   Fsharp4, Fsharp4, B3,      B3,      C4, C4, Gsharp4, Gsharp4, D4, D4,
                                   Fsharp4, Fsharp4, B3,      B3,      C4, C4, Gsharp4, Gsharp4, D4, D4,
    
                                   Dsharp4, Dsharp4, B4,      B4,      F4, F4, Gsharp4, Gsharp4, Asharp4, Asharp4,
                                   Dsharp4, Dsharp4, B4,      B4,      F4, F4, Gsharp4, Gsharp4, Asharp4, Asharp4,
    
                                   C5,      C5,      Csharp5, Csharp5, D5, D5, Dsharp5, Dsharp5, F5, F5,
                                   C5,      C5,      Csharp5, Csharp5, D5, D5, Dsharp5, Dsharp5, F5, F5,
    
                                   F5,      F5,      Gsharp5, Gsharp5, Asharp5, Asharp5, C5,      C5,      F6, F6,
                                   F5,      F5,      Gsharp5, Gsharp5, Asharp5, Asharp5, C5,      C5,      F6, F6};

/*BAT TRIP JAVA
static float tones[NUM_WAVES] = {  Cplus3,      Cplus3,      Dplus3, Dplus3, E3, E3, Fplus3, Fplus3, E3, E3,
                                   Cplus3,      Cplus3,      Dplus3, Dplus3, E3, E3, Fplus3, Fplus3, E3, E3,
	
                                   Gsharpplus3, Gsharpplus3, Aplus3,      Aplus3,      Cplus4, Cplus4, Dplus4, Dplus4, E4, E4,
                                   Gsharpplus3, Gsharpplus3, Aplus3,      Aplus3,      Cplus4, Cplus4, Dplus4, Dplus4, E4, E4,

                                   Fplus4, Fplus4, Cplus4,      Cplus4,      E4, E4, Gsharpplus4, Gsharpplus4, Aplus4, Aplus4,
                                   Fplus4, Fplus4, Cplus4,      Cplus4,      E4, E4, Gsharpplus4, Gsharpplus4, Aplus4, Aplus4,

                                   Cplus4,      Cplus4,      Dplus4, Dplus4, E4, E4, Gsharpplus4, Gsharpplus4, Fplus4, Fplus4,
                                   Cplus4,      Cplus4,      Dplus4, Dplus4, E4, E4, Gsharpplus4, Gsharpplus4, Fplus4, Fplus4,

                                   E4,      E4,      Gsharpplus4, Gsharpplus4, Aplus5, Aplus5, Cplus5,      Cplus5,      E5, E3,
                                   E4,      E4,      Gsharpplus4, Gsharpplus4, Aplus5, Aplus5, Cplus5,      Cplus5,      E5, E5};
*/ 
/*
C Csharp Dsharp E F Fsharp Gsharp Asharp B*/
/*static float tones[NUM_WAVES] = {  E3,      E3,      E3,E3,  Dsharp3, Dsharp3,   E3, E3, Fsharp3, Fsharp3, 
                                   E3,      E3,      E3,E3,  Dsharp3, Dsharp3,   E3, E3, Fsharp3, Fsharp3,  
                                     
                              A3, A3,     Dsharp3, Dsharp3, A4,      A4,  B4, B4,    C4, C4,  
                              A3, A3,     Dsharp3, Dsharp3, A4,      A4,  B4, B4,    C4, C4,  
                                                                                                                                  
                              C4, C4,     Dsharp4, Dsharp4,   E4, E4,  Fsharp4, Fsharp4, Fsharp4, Fsharp4, 
                              C4, C4,     Dsharp4, Dsharp4,   E4, E4,  Fsharp4, Fsharp4, Fsharp4, Fsharp4, 

                               Gsharp4, Gsharp4,    A5,      A5,  B5, B5,    C5, C5, C5, C5,
                               Gsharp4, Gsharp4,    A5,      A5,  B5, B5,    C5, C5, C5, C5,

                               Dsharp5, Dsharp5,   E5, E5,  Fsharp5, Fsharp5, Fsharp5, Fsharp5, C4, C4, 
                               Dsharp5, Dsharp5,   E5, E5,  Fsharp5, Fsharp5, Fsharp5, Fsharp5, C4, C4};
*/

#endif
