#include<stdio.h>
int fact(int n);
void main(){
    int n;
    printf("Enter number: ");
    scanf("%d",&n);
    int factnumber = fact(n);
    printf("%d",factnumber);

   
}
 int fact(int n) {

        if((n == 0 || n == 1) == 1){
            return 1;
        }
        return n * fact(n-1);
    }











    
    /* Find prime number   */

// import java.util.Scanner;


// public class Prime {
//     public static void main(String[] args) {
//         Scanner sc = new Scanner(System.in);
//         System.out.println("Enter a Number: ");
//         int n = sc.nextInt();
//         if(n==2){
//             System.out.println("n is prime: ");
//         }
//         else{
//             boolean a = true;

//             for(int i=2;i<=n/2;i++){
//                 if(n % i == 0){
//                  a = false;
//                 }
//             }

//             if(a == true){
//                 System.out.println("n is prime: ");
//             }
//             else{
//                 System.out.println("n is not prime: ");
//             }
//         }

//     }
    
// }


