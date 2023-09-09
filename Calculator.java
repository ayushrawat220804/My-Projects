import java.util.Scanner;

public class Calculator {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        // Take input from user till user does not press X or x
        int ans = 0;
        while (true) {
            // take the operator as input
            System.out.print("Enter the operator: ");
            char op = in.next().trim().charAt(0);

            if (op == '+' || op == '-' || op == '*' || op == '/' || op == '%') {
                // input two numbers
                System.out.println("Input any two number:");
                System.out.print("Enter the 1st number: ");
                int num1 = in.nextInt();
                System.out.print("Enter the 2nd number: ");
                int num2 = in.nextInt();

                if (op == '+') {
                    ans = num1 + num2;
                }
                if (op == '-') {
                    ans = num1 - num2;
                }
                if (op == '*') {
                    ans = num1 * num2;
                }
                if (op == '/') {
                    if (num2 != 0) {
                        ans = num1 / num2;
                    }
                }
                if (op == '%') {
                    ans = num1 % num2;
                }
            } else if (op == 'x' || op == 'X')
            {
                System.out.println("\u001B[31m" + "Successfully exit." + "\u001B[0m");
                break;
            } else {
                System.out.println("Invalid operation!!");
            }
            System.out.print("Hence, your output of two numbers is: ");
            System.out.println("\u001B[32m" + ans + "\u001B[0m");
            System.out.println("wanted to close the calculator, press 'X' or 'x' to exit.");
        }
    }
}