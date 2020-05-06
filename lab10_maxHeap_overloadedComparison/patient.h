/*
 * @project: MaxHeap - Hospital queue simulation
 * @file: patient.h
 * @author: Jack Gould
 * @brief: Header file for patient class. Lists member methods. These objects will fill the maxHeap, so that the heap can compare them for feeding into a hospital queue. Comparison operators overloaded for compatibility with maxHeap.
 * @date: 04-17-2020
 */

#ifndef PATIENT_H
#define PATIENT_H

#include <string>


class patient
{
     private:
     std::string m_fName; //string storing this patients name
     std::string m_lName;
     int m_age; //int storing this patients age
     std::string m_condition; //string storing this patients illness to be treated at the Hospital
     int m_severity; //int storing the severity level of the patients condition, for proper maxHeap placement
     int m_arrivalOrder;

     
     public:
     /** 
     * @pre 
     * @param std::string fName: first name of patient
     * @param std::string lName: last name of patient
     * @param int age: age of patient to be created
     * @param int severity: 0-9 int of the severity level of patients illsee
     * @param std::string condition - Illness affecting the patient
     * @param arrivalOrder - number indicating the order the individual arrived to the hospital. Used to break ties between patients with same severity and age
     * @post Constructor for patient object which assigns member variables to the passed in parameters.
     **/     
     patient(std::string fName, std::string lName, int age, std::string condition, int severity, int arrivalOrder);

     /** Constructor without parameters
     * @pre 
     * @post Empty constructor for patient object which creates a new patient; Initializes member variables to base states.
     **/     
     patient();
//     ~patient();
     
     /** Assignment Operator Overloading
     * @pre 
     * @param const patient& rhs - A patient object to be copied
     * @return patient& - The calling object is made to be an identical copy to the passed in patient
     **/     
     patient& operator=(const patient& rhs);


     /** Comparison Operator > Overloading
     * @pre 
     * @param const patient& rhs - A patient object to compare to 
     * @return bool - Returns true if severity level is greater that the parameter's. If they are equal, it then looks for a greater age. If those are equal, looks for who has a lower arrivalOrder.
     **/     
     bool operator>(const patient& rhs);


     /** 
     * @pre 
     * @return Returns age of the patient
     **/     
     int getAge() const;
    
     /** 
     * @pre 
     * @return Returns the condition that this patient suffers from
     **/
     std::string getCondition() const;

     /** 
     * @pre 
     * @return int - Returns the severity level of this patients illness
     **/
     int getSeverity() const;

     /** 
     * @pre 
     * @return Returns the last name of this patient
     **/
     std::string getLast() const;

     /** 
     * @pre 
     * @return Returns the first name of this patient
     **/
     std::string getFirst() const;
};
#endif
