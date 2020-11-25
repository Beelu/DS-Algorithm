import java.util.*;
import java.lang.*;
import java.text.DecimalFormat;
import java.text.NumberFormat;  

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String poly1 = scanner.nextLine();
        String poly2 = scanner.nextLine();
        ArrayList sortpoly1 = new ArrayList();
        ArrayList sortpoly2 = new ArrayList();
        String result = "";
        NumberFormat nf = new DecimalFormat("#.##"); 

        firstsort(poly1, sortpoly1);
        firstsort(poly2, sortpoly2);

        int n1 = 0, n2 = 0;
        while(n1 < sortpoly1.size() && n2 < sortpoly2.size()){
            String[] splited1 = sortpoly1.get(n1).toString().split("x");
            String[] splited2 = sortpoly2.get(n2).toString().split("x");

            if(Integer.valueOf(splited1[1]) > Integer.valueOf(splited2[1])){
                if(n1 == 0 && !result.equals("") && Integer.valueOf(splited1[0]) > 0){
                    result += "+";
                }
                result += splited1[0] + "x^" + splited1[1];
                n1 += 1;
            }
            else if(Integer.valueOf(splited1[1]) < Integer.valueOf(splited2[1])){
                if(n2 == 0 && !result.equals("") && Integer.valueOf(splited2[0]) > 0){
                    result += "+";
                }
                result += splited2[0] + "x^" + splited2[1];
                n2 += 1;
            }
            else{
                float coef = Float.parseFloat(splited1[0]) + Float.parseFloat(splited2[0]);
                if(!result.equals("") && coef > 0){
                    result += "+";
                }
                if(Integer.valueOf(splited1[1]) != 0){
                    result += nf.format(coef) + "x^" + splited1[1];
                }else{
                    result += nf.format(coef);
                }
                n1 += 1;
                n2 += 1;
            }
        }

        if(n1 == sortpoly1.size()){
            while(n2 < sortpoly2.size()){
                String[] splited2 = sortpoly2.get(n2).toString().split("x");
                if(Integer.valueOf(splited2[1]) != 0){
                    result += splited2[0] + "x^" + splited2[1];
                }else{
                    result += splited2[0];
                }
                n2 += 1;
            }
        }else{
            while(n1 < sortpoly1.size()){
                String[] splited1 = sortpoly1.get(n1).toString().split("x");
                if(Integer.valueOf(splited1[1]) != 0){
                    result += splited1[0] + "x^" + splited1[1];
                }else{
                    result += splited1[0];
                }
                n1 += 1;
            }
        }

        System.out.print(result);
    }

    //Functions
    public static void firstsort(String poly, ArrayList coef){
        int n=0;                /*go through string */
        String substr = "";   
    
        while(n<poly.length()){
            if(poly.substring(n,n+1).equals("+") || poly.substring(n,n+1).equals("-")){
                if(!substr.equals("")){coef.add(substr);}
                substr = "";
                substr += poly.substring(n,n+1);
            }
            else if(poly.substring(n,n+1).equals("^")){}
            else{
                substr += poly.substring(n,n+1);
            }
            if(n == poly.length()-1){
                if(!substr.contains("x")){
                    substr += "x0";
                }
                coef.add(substr);
            }
            n+=1;
        }
    }
}