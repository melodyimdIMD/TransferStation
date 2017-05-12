#include "pi.h"
typedef enum MCU_PIN_tag{
    CLK,
    CS,  //low enable
    DATA,
    KEY, //low enable
}MCU_PIN;

typedef enum PIN_VALUE_tag{
    LOW,
    HIGH
}PIN_VALUE;


/*#define CS   PI_PIN_1
#define CLK  PI_PIN_1
#define DATA PI_PIN_1
#define KEY  PI_PIN_1

#define LOW   0
#define HiGH  1
*/
static void setPinValue(MCU_PIN pin,PIN_VALUE value){
    //to d
}

void write7279(unsigned char cmd,unsigned char data){
    send_byte(cmd);
    send_byte(data);
}

unsigned char read7279(unsigned char command){
    send_byte(command);
    return(receive_byte());
}

void send_byte(unsigned char aByte){
    //cs low
    setPinValue(CS,LOW);
    long_delay();
    for(int i = 0; i < 8 ; i++){
        if(aByte & (0x80 >> i)){
           setPinValue(DATA,HIGH);
        }else{
           setPinValue(DATA.LOW);
        } 
        setPinValue(CLK,HIGH);
        short_delay();
        setPinValue(CLK,LOW);
        short_delay();
    } 
}

int getPinValue(){
    return ;
}
void receive_byte(){
    long_delay();
    int inByte;
    setPinValue(DATA,HIGH);//set input status
    for(int i = 0;i < 8 ;i++){
       setPinValue(CLK,HIGH); 
       short_delay();
       inByte |= (getPinValue(DATA) << (7 - i));
       setPinValue(CLK,LOW);
       short_delay();

    }
    setPinValue(DATA,LOW);
    return inByte;
}

void long_delay(){
    
}

void short_delay(){
    
}
