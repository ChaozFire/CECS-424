import java.io.*;
import java.util.Scanner;

public class Assn2 {
  public static void main(String[] args)
  {
    try {
      File file = new File(args[0]);
      Scanner readFile = new Scanner(file);
      String regex = "^[$][*]*"
      + "([0]|([1-9][\\d]{2}|[1-9][\\d]|[1-9])([,][\\d]{3})*)?"
      + "([.][\\d]{2})?$";

      while (readFile.hasNextLine()) {
        String line = readFile.nextLine();
        if(line.matches(regex)) {
          System.out.println("Matched: " + line);
        }
        else {
          System.out.println("Not matched: " + line);
        }
      }
    } catch(FileNotFoundException fnf) {

    }
  }
}
