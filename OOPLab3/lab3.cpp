#include "song.h"

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>
using namespace std;



Song::Song(const string& file){
    int tempo; 
    string line;

    ifstream in;
    in.open(file);
    if(!in.is_open()){
        cout << "There was a problem opening the input file please restart"<<endl;
        return ;
    }

    in >> tempo;
    

    while(!in.eof()){
        getline(in, line, '\n');
        addVoice(Voice(line));
    }
    
}

Voice::Voice(const string& str, double vol, instrument_t instr){
    setVolume(vol);
    setInstrument(instr);

    string temp="";
    istringstream buffer(str);
    while(!buffer.fail()){
            while(buffer>>temp){
                
                if(buffer.fail()){
                    buffer.clear();
                    buffer.ignore(1000,'\n');
                    break;
                }
                addNote(Note(temp));
            }

        }

    }




    
    
Note::Note(string str){
    for(int i =1;i<str.size();i++){
        if((str.at(i) >= 'A' && str.at(i) <= 'G') || str.at(i)=='R'){
           switch(str.at(i)){
               case 'A': pitch = A;
                          break;
               case 'B': pitch = B;
                         break;
               case 'C': pitch = C;
                         break;
               case 'D': pitch = D;
                         break;
               case 'E': pitch = E;
                         break;
               case 'F': pitch = F;
                         break;
               case 'G': pitch = G;
                         break;
               case 'R': pitch = REST;
                         break;
           }
           if(str.at(i+1)=='b'){
               
                switch(str.at(i)){
                    case 'A': pitch = Ab;
                              break;
                    case 'B': pitch = Bb;
                              break;
                    case 'D': pitch = Db;
                             break;
                    case 'E': pitch = Eb;
                             break;
                    case 'G': pitch = Gb;
                             break;
                    
                }
           }
            if(str.at(i+1)=='#'){
                
                switch(str.at(i)){
                    case 'A': pitch =Bb;
                            break;
                    case 'C': pitch =Db;
                            break;
                    case 'D': pitch=Eb;
                            break;
                    case 'F': pitch=Gb;
                            break;
                    case 'G': pitch=Ab;
                            break;
                    
                }
            }
            
            continue;
        }
        
        
            if(str.at(i) >='0' && str.at(i)<='7'){
                    octave = str.at(i)-48;
                    
                    continue;
            }
            if(str.at(i) >='a' && str.at(i) <='z'){
                switch(str.at(i)){
                    case 'q': duration = 1;
                      break;
                    case 'h': duration = 2;
                      break;
                    case 'w': duration = 4;
                      break;
                    case 'e': duration = 0.5;
                      break;
                    case 's': duration = 0.25;
                      break;
                }
                continue;
            }
            if(str.at(i) == '.'){
                duration = duration * 1.5;
                
            }
    
    }
    
}


ostream& operator<<(ostream& out, const Song&){

    return out;
}

ostream& operator<<(ostream& out, const Voice&){
    return out;
}

ostream& operator<<(ostream& out, const Note&){

    return out;
}
