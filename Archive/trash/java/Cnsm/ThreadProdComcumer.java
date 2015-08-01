/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package threadprodcomcumer;

/**
 *
 * @author sds
 */
public class ThreadProdComcumer {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws InterruptedException {
        Queue q = new Queue();
        CpuConsumer consumer = new CpuConsumer(q);
        ProcessProducer producer = new ProcessProducer(q);
        consumer.start();
        producer.start();
        
        
        Thread.sleep(5000);
        consumer.interrupt();
        producer.interrupt();
                
        
    }
}
