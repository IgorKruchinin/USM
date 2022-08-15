# USM
Universal Storage Manager Library (for my projects)

Overview

USM is Universal Storage Manager for creating profiles. It's writes data in .uto file (Usm Text Object)

Example of .uto file:
i<sectionname>146|<\e>587|<\e>

Coding 146 and 587 int values

"i" before <sectionname> is a format specifier. The "i" mean integer, also possible the "s" format specifier (means string). Next comes the name of section. Next comes int or string values, each of them ends as |<\e>
s<sectionname>Hello|<\e>It's wonderful|<\e>

Coding "Hello" and "It's wonderful" string values
API Description:

Include "USM/USM.h" and define a Profile Storage object as first:
ProfileStorage ps("NameOfYourProfileStorage");

ps.create_ssec("StringSectionName"); // Creates a string section

ps.create_isec("IntSectionName"); // Creates a int section

ps.gets("StringSectionName").add(127); // Adds the 127 value into your int section

ps.geti("IntSectionName").add("Hello!"); // Adds the "Hello!" value into your string section

ps.to_file(); // Writes changes to NameOfYourProfileStorage.uto file;

size_t size = ps.gets("StringSectionName").size(); // Returns and write into the "size" variable count of objects in your string section

size_t size = ps.geti("IntSectionName").size(); // Returns and write into the "size" variable count of objects in your int section

int a = ps.geti("IntSectionName")[0]; // Return and write into the "a" variable element with index 0 from your int section

std::string b = ps.gets("IntSectionName")[0]; // Return and write into the "b" variable element with index 0 from your string section

bool is_opened = ps.opened(); // Returns 1 if ProfileStorage are opened from .uto file in constructor, and 0 if the ProfileStorage created clear (Usually the first profile opening
Compilation:

Compiles with linking with USM.cpp and Section.cpp files

Warning!
Add "bool USM_CONFIG::InTextMode = 1;" in your main cpp file in global space
