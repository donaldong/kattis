import java.util.*;
 
public class classy{
 
    static Map<String, Integer> classValues;
 
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
 
        classValues = new HashMap<>();
        classValues.put("upper", 3);
        classValues.put("middle", 2);
        classValues.put("lower", 1);
 
        int T = sc.nextInt();
        while(T --> 0){
            int n = sc.nextInt();
 
            List<Person> people = new ArrayList<Person>(n);
            for(int i = 0; i < n; i++){
                String name = sc.next();
                name = name.substring(0, name.length() - 1);
 
                String[] classes = sanitizeClassInput(sc.next());
 
 
                people.add(new Person(name, new PersonClass(classes)));
 
                //consume "class"
                sc.next();
            }
 
            Collections.sort(people);
 
            for(int i = 0; i < people.size(); i++){
                System.out.println(people.get(i).name);
            }
 
            System.out.println("==============================");
        }
    }
 
    static String[] sanitizeClassInput(String nonSanitizedClasses){
        String[] revClasses = nonSanitizedClasses.split("-");
        String[] classes = new String[revClasses.length];
        for(int j = revClasses.length - 1; j >= 0; j--){
            classes[(revClasses.length-1)-j] = revClasses[j].toLowerCase();
        }
 
        return classes;
    }
 
    static class Person implements Comparable<Person>{
        String name;
        PersonClass prsClass;
 
        public Person(String name, PersonClass prsClass){
            this.name = name;
            this.prsClass = prsClass;
        }
 
        public int compareTo(Person other){
           
            System.out.println("Comparing:\n" + this + "\nto\n" + other + "\n\n");
           
            int classComparison = this.prsClass.compareTo(other.prsClass);
            //return (classComparison == 0 ? this.name.compareTo(other.name) : classComparison);
            return classComparison;
        }
 
        public String toString(){
            String representation = name + "\n" + Arrays.toString(prsClass.classes);
            return representation;
        }
 
    }
 
    static class PersonClass implements Comparable<PersonClass>{
        String[] classes;
 
        public PersonClass(String[] classes){
            this.classes = classes;
        }
 
        public int compareTo(PersonClass other){
            int thisCurrClass = 0;
            int otherCurrClass = 0;
            return 0;
        }
    }
}
