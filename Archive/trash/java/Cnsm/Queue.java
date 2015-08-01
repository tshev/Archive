/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package threadprodcomcumer;

import java.util.LinkedList;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author sds
 */
public class Queue {
    List<Product> items = new LinkedList<Product>();
    public static int MAX_SIZE = 10;
    public synchronized void push(Product item) {
        if( items.size() >= MAX_SIZE ){
            try {
                wait();
            } catch (InterruptedException ex) {
                Logger.getLogger(Queue.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
        items.add(item);
        notify();
    }
    
    public synchronized Product pull(){
        if( items.isEmpty() ){
            try {
                wait();
            } catch (InterruptedException ex) {
                Logger.getLogger(Queue.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
        notify();
        return items.remove(0);
        
    }
    
}
