#include <CoreAudio/CoreAudio.h>
#include <CoreFoundation/CFURL.h>
#include <CoreFoundation/CFBundle.h>
#include <AudioToolbox/AudioToolbox.h>
#include <AudioToolbox/ExtendedAudioFile.h>
//#include <ApplicationServices/ApplicationServices.h>

#include "MIDIChango.h"
#include "miditones.h"

static float mtones[NUM_WAVES] = {  mC3,      mC3,      mCsharp3, mCsharp3, mD3, mD3, mDsharp3, mDsharp3, mG3, mG3,
                                   mC3,      mC3,      mCsharp3, mCsharp3, mD3, mD3, mDsharp3, mDsharp3, mG3, mG3, 
	                             
                                   mGsharp3, mGsharp3, mA3,      mA3,      mC4};
 



MIDIPortRef outputPort;
MIDIEndpointRef eps[6];
MIDIPacketList packetList;

MIDIChango::MIDIChango(Mahalo *M){

  fprintf(stderr,"DOING THE MIDI THING!\n");
  MIDIClientRef client;
  MIDIClientCreate(
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

MIDIChango::~MIDIChango(){
    

}

void MIDIChango::tune(long which, float freq){
    

}

void MIDIChango::update(float *vals){


  for( int i = 0; i < NUM_WAVES ; i ++  ){

   
      /*On*/
      packetList.numPackets = 1;
      packetList.packet[0].length = 3;
      packetList.packet[0].data[0] = 0x90; // note ON
      packetList.packet[0].data[1] = 0x7f & ((int)mtones[i]); // C
      packetList.packet[0].data[2] = ((int)(vals[i]*127)); // velocity
      packetList.packet[0].timeStamp = 0;
      MIDISend(outputPort,eps[i],&packetList); 
   
    fflush(stdout);

  }
  
}
