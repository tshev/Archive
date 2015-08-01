/**
 * Created by tshev on 4/9/15.
 */
public class MainApp {
    static {
        System.out.println("begin");
        main(null);
        System.out.println("end");
        second();
    }

    public static void main(String[] argv) {
        if (argv != null) return;
        System.out.println("hello from main!!!!");
    }
    public static void second() {
        Counter counter = new Counter();
        for (int i = 0; i < 99; i++) {
            counter.increment();
        }
        System.out.printf("Count of resets %d \n", counter.getCountOfResets());
    }
}
final class Counter {
    private int upperLimit;
    private int lowerLimit;
    private int counter ;
    private int resetCount ;

    public Counter() {
        upperLimit = 10;
    }
    public Counter(int upperLimit, int lowerLimit) {
        this.upperLimit = upperLimit;
        this.lowerLimit = lowerLimit;
    }
    public int getLowerLimit() {
        return lowerLimit;
    }

    public void setLowerLimit(int lowerLimit) {
        this.lowerLimit = lowerLimit;
    }

    public int getUpperLimit() {
        return upperLimit;
    }

    public void setUpperLimit(int upperLimit) {
        this.upperLimit = upperLimit;
    }
    public int getCountOfResets() {
        return resetCount;
    }

    public void increment() {
        if (counter < upperLimit) {
            counter++;
        } else {
            counter = lowerLimit;
            resetCount++;
        }
    }
}
