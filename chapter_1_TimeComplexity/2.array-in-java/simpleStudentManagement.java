import java.util.Arrays;

class Student{
    private int roll_no;
    private String name;
    Student(int roll_no, String name){
        this.roll_no = roll_no;
        this.name = name;
    }
    
    public int getStudentRollNo()
    {
        return this.roll_no;
    }
    
    public String getStudentName()
    {
        return this.name;
    }
    
    
}

public class simpleStudentManagement{
    void printListStudent(Student a[])
    {
        for (Student st : a)
        {
            System.out.printf("Roll no: %d - Name: %s\n", st.getStudentRollNo(), st.getStudentName());
        }
    }
    public void management()
    {
        Student listStudents[] = {
          new Student(1, "Nam"),
          new Student(2, "Hoang"),
          new Student(3, "Nu"),
          new Student(4, "Bac"),
          new Student(5, "Viet"),
        };
        printListStudent(listStudents);
    }
}