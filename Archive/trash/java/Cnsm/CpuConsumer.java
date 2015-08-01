/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package threadprodcomcumer;

import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author sds
 */
public class CpuConsumer extends Thread {
    Queue queue;

    public CpuConsumer(Queue queue) {
        this.queue = queue;
    }
    
    public void run(){
        while( ! isInterrupted()){
            Product prod = queue.pull();
            if( prod != null){
                try {
                    Thread.sleep(prod.time);
                    System.out.println("Task is performing");
                } catch (InterruptedException ex) {
                   return;
                }
            }
        }
    }
    
}
