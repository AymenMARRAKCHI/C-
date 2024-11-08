/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/testFiles/simpletest.cpp to edit this template
 */

/* 
 * File:   newsimpletest1.cpp
 * Author: etudiant
 *
 * Created on 10 avril 2024, 02 h 09
 */

#include <stdlib.h>
#include <iostream>

/*
 * Simple C++ Test Suite
 */

void
test1 ()
{
  std::cout << "newsimpletest1 test 1" << std::endl;
}

void
test2 ()
{
  std::cout << "newsimpletest1 test 2" << std::endl;
  std::cout << "%TEST_FAILED% time=0 testname=test2 (newsimpletest1) message=error message sample" << std::endl;
}

int
main (int argc, char** argv)
{
  std::cout << "%SUITE_STARTING% newsimpletest1" << std::endl;
  std::cout << "%SUITE_STARTED%" << std::endl;

  std::cout << "%TEST_STARTED% test1 (newsimpletest1)" << std::endl;
  test1 ();
  std::cout << "%TEST_FINISHED% time=0 test1 (newsimpletest1)" << std::endl;

  std::cout << "%TEST_STARTED% test2 (newsimpletest1)\n" << std::endl;
  test2 ();
  std::cout << "%TEST_FINISHED% time=0 test2 (newsimpletest1)" << std::endl;

  std::cout << "%SUITE_FINISHED% time=0" << std::endl;

  return (EXIT_SUCCESS);
}

