package ProducerConsumer;

import java.util.Scanner;
public class ProducerConsumer {
	static int s=1;
	static int e=10;
	static int f=0;
	static int i;

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		
        while(true){
            System.out.println("Enter Your Choice"+"\n"+"1)produce"+"\n"+ "2)consume"+"\n"+ "3)exit"+"\n");
            int ch;            
            ch=sc.nextInt();
            
            switch(ch){
            	case 1: if(s==1&&e!=0){
                      		producer();  
                    	}
                 		else
                 			System.out.println("producer is waiting");
                 		break;
                case 2: if(s==1&&f!=0){
                      		consumer();  
                    	}
                 		else
                 			System.out.println("consumer  is waiting");
                 		break;
                case 3: System.exit(0);
                		break;
                default:System.out.println("You Choose Incorrect Option...");
             }
        }
    }
 
	static int wait(int s){
     return --s;   
     }
  
 static  int signal(int s){
        return ++s;
    }
  
   static void producer(){
        s=wait(s);
        e=wait(e);
        f=signal(f);
        i++;
        System.out.println("producer is producing "+i);
        s=signal(s);
    }
   
   static void consumer(){
        s=wait(s);
        e=signal(e);
        f=wait(f);
        i--;
        System.out.println("consumer is consuming "+i);
        s=signal(s);
	}
}
