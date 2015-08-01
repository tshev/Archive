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
public class ProcessProducer extends Thread {
    Queue queue;

    public ProcessProducer(Queue queue) {
        this.queue = queue;
    }
    public void run(){
        while(!isInterrupted()){
            queue.push( new Product(20) );
            try {
                Thread.sleep(20);
            } catch (InterruptedException ex) {
                return;
            }
        }
    }
}
