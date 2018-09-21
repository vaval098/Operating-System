
package readwrite;

import java.io.Reader;
import java.util.concurrent.Semaphore;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Readwrite {
    
    static int rc=0;
    static Semaphore s=new Semaphore(1);
    static Semaphore wrt=new Semaphore(1);
    
    static class Reader implements  Runnable{
        public void run()
        {
            try {
                s.acquire();
                rc=rc+1;
                if(rc==1)
                    wrt.acquire();
                s.release();
                
                System.out.println(Thread.currentThread().getName()+"is reading...");
                Thread.sleep(500);
                
                s.acquire();
                rc=rc-1;
                if(rc==0)
                    wrt.release();
                s.release();
            } catch (InterruptedException ex) {
                Logger.getLogger(Readwrite.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
        
    }
    
    static class Writer implements Runnable
    {
        public void run()
        {
            try {
                wrt.acquire();
                System.out.println(Thread.currentThread().getName()+"is writing...");
                Thread.sleep(1000);
                wrt.release();
            } catch (InterruptedException ex) {
                Logger.getLogger(Readwrite.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }
    
    public static void main(String[] arg)
    {
        Reader r=new Reader();
        Writer w=new Writer();
        Thread t1=new Thread(r);
        t1.setName("T1");
        t1.start();
        Thread t2=new Thread(w);
        t2.setName("T2");
        t2.start();
        Thread t3=new Thread(w);
        t3.setName("T3");
        t3.start();
        Thread t4=new Thread(r);
        t4.setName("T4");
        t4.start();
    }
    
    
}
