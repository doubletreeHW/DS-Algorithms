import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if(sc.hasNextInt()) {
            int num = sc.nextInt();
            
            for(int i = 1; i <= 9; i++) {
                System.out.printf("%d * %d = %d\n", num, i, num * i);
            }
        }
        
        sc.close();
    }
}