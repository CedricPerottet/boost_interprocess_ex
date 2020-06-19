#include <boost/interprocess/ipc/message_queue.hpp>
#include <iostream>
#include <vector>

using namespace boost::interprocess;

int main ()
{
   try{
      //Create a message_queue.
      message_queue mq
         (open_or_create               //only create
         ,"message_queue"           //name
         ,100                       //max message number
         ,sizeof(int)               //max message size
         );

      //Send 100 numbers
      for(int i = 0; i < 100; ++i){
         std::cout << "get_num_msg() = " << mq.get_num_msg() << std::endl;
         std::cout << "sending " << i << std::endl;
         mq.send(&i, sizeof(i), 0);
         std::cout << "sent " << i << std::endl;
      }
   }
   catch(interprocess_exception &ex){
      std::cout << ex.what() << std::endl;
      return 1;
   }

   return 0;
}