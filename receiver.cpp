#include <boost/interprocess/ipc/message_queue.hpp>
#include <iostream>
#include <vector>

using namespace boost::interprocess;

int main ()
{
   try{
      //Open a message queue.
      message_queue mq
         (open_only        //only create
         ,"message_queue"  //name
         );

      unsigned int priority;
      std::size_t recvd_size;

      //Receive 100 numbers
      for(int i = 0; i < 100; ++i){
         int number;
         std::cout << "get_num_msg() = " << mq.get_num_msg() << std::endl;
         std::cout << "receiving msg" << std::endl;
         mq.receive(&number, sizeof(number), recvd_size, priority);
         std::cout << "received " << number << std::endl;
         if(number != i || recvd_size != sizeof(number)){
            std::cout << "recvd_size : " << recvd_size << std::endl;
            std::cout << "number : " << number << std::endl;
            std::cout << "i : " << i << std::endl;
            return 1;
         }
      }
   }
   catch(interprocess_exception &ex){
      message_queue::remove("message_queue");
      std::cout << ex.what() << std::endl;
      return 1;
   }
   // Only for destroying message_queue : 
   // message_queue::remove("message_queue");
   // std::cout << "removed message_queue and exit with 0" << std::endl;
   return 0;
}