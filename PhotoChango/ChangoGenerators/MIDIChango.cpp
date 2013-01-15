#include <CoreAudio/CoreAudio.h>
#include <CoreFoundation/CFURL.h>
#include <CoreFoundation/CFBundle.h>
#include <AudioToolbox/AudioToolbox.h>
#include <AudioToolbox/ExtendedAudioFile.h>
//#include <ApplicationServices/ApplicationServices.h>

#include "MIDIChango.h"
#include "miditones.h"
static float lastvals[NUM_WAVES];
static float mtones[NUM_WAVES] = {  mC3,      mC3,      mCsharp3, mCsharp3, mD3, mD3, mDsharp3, mDsharp3, mG3, mG3,
                                   mC3,      mC3,      mCsharp3, mCsharp3, mD3, mD3, mDsharp3, mDsharp3, mG3, mG3, 
	                             
                                   mGsharp3, mGsharp3, mA3,      mA3,      mC4, mC4, mCsharp4, mCsharp4, mD4, mD4,
                                   mGsharp3, mGsharp3, mA3,      mA3,      mC4, mC4, mCsharp4, mCsharp4, mD4, mD4,

                                   mDsharp4, mDsharp4, mF4,      mF4,      mG4, mG4, mGsharp4, mGsharp4, mA4, mA4,
                                   mDsharp4, mDsharp4, mF4,      mF4,      mG4, mG4, mGsharp4, mGsharp4, mA4, mA4,

                                   mC5,      mC5,      mCsharp5, mCsharp5, mD5, mD5, mDsharp5, mDsharp5, mF5, mF5,
                                   mC5,      mC5,      mCsharp5, mCsharp5, mD5, mD5, mDsharp5, mDsharp5, mF5, mF5,

                                   mG5,      mG5,      mGsharp5, mGsharp5, mA5, mA5, mC5,      mC5,      mGsharp6, mGsharp6,
                                   mG5,      mG5,      mGsharp5, mGsharp5, mA5, mA5, mC5,      mC5,      mGsharp6, mGsharp6};
 

MIDIPortRef outputPort;
MIDIEndpointRef eps[6];
MIDIPacketList packetList;

MIDIChango::MIDIChango(Mahalo *M){

  fprintf(stderr,"DOING THE MIDI THING!\n");
  MIDIClientRef client;
  OSStatus result = MIDIClientCreate(
  CFStringCreateWithCString(NULL, "D-Ball's Client", kCFStringEncodingASCII),
  NULL,
  NULL,
  &client);

  MIDIOutputPortCreate(client, CFSTR("My output port"), &outputPort);
  for(int i = 0 ; i < 6; i++){
    eps[i] = MIDIGetDestination(i);
  }
  //this->m = M;

  //SampleMixer *s = new SampleMixer();

  //for ( int i = 0; i < NUM_WAVES; i++ ){

  //}
  
  //m->setSampleSource(s); 

}

void MIDIChango::tune(long which, float freq){
    

}

void MIDIChango::update(float *vals){


  for( int i = 0; i < NUM_WAVES ; i ++  ){

    //this->srcs[i]->setAmpVal( vals[i] );
    
    int which = i % 6; 
      
      /*On*/
      packetList.numPackets = 1;
      packetList.packet[0].length = 3;
      packetList.packet[0].data[0] = 0x90; // note ON
      packetList.packet[0].data[1] = 0x7f & ((int)mtones[i]); // C
      packetList.packet[0].data[2] = ((int)(vals[i]*127)); // velocity
      packetList.packet[0].timeStamp = 0;
      MIDISend(outputPort,eps[i],&packetList); 
    //if( vals[i] < lastvals[i] ){    

      //printf("%d %d %d 0\n",which,(int)(vals[i] * 127), (int)mtones[i]);
      

    //}
    //if( vals[i] != lastvals[i] ){    

      //printf("%d %d %d 1\n",which,(int)(vals[i] * 127), (int)mtones[i]);

    //}

    //lastvals[i] = vals[i];
    fflush(stdout);

  }
  
}
