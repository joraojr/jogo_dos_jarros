# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/joraojr/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/181.5281.33/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/joraojr/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/181.5281.33/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/joraojr/Documentos/jorao/ufjf/IA/jogo_dos_jarros

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/joraojr/Documentos/jorao/ufjf/IA/jogo_dos_jarros/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/jogo_dos_jarros.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/jogo_dos_jarros.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/jogo_dos_jarros.dir/flags.make

CMakeFiles/jogo_dos_jarros.dir/main.cpp.o: CMakeFiles/jogo_dos_jarros.dir/flags.make
CMakeFiles/jogo_dos_jarros.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/joraojr/Documentos/jorao/ufjf/IA/jogo_dos_jarros/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/jogo_dos_jarros.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/jogo_dos_jarros.dir/main.cpp.o -c /home/joraojr/Documentos/jorao/ufjf/IA/jogo_dos_jarros/main.cpp

CMakeFiles/jogo_dos_jarros.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/jogo_dos_jarros.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/joraojr/Documentos/jorao/ufjf/IA/jogo_dos_jarros/main.cpp > CMakeFiles/jogo_dos_jarros.dir/main.cpp.i

CMakeFiles/jogo_dos_jarros.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/jogo_dos_jarros.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/joraojr/Documentos/jorao/ufjf/IA/jogo_dos_jarros/main.cpp -o CMakeFiles/jogo_dos_jarros.dir/main.cpp.s

CMakeFiles/jogo_dos_jarros.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/jogo_dos_jarros.dir/main.cpp.o.requires

CMakeFiles/jogo_dos_jarros.dir/main.cpp.o.provides: CMakeFiles/jogo_dos_jarros.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/jogo_dos_jarros.dir/build.make CMakeFiles/jogo_dos_jarros.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/jogo_dos_jarros.dir/main.cpp.o.provides

CMakeFiles/jogo_dos_jarros.dir/main.cpp.o.provides.build: CMakeFiles/jogo_dos_jarros.dir/main.cpp.o


CMakeFiles/jogo_dos_jarros.dir/Estado.cpp.o: CMakeFiles/jogo_dos_jarros.dir/flags.make
CMakeFiles/jogo_dos_jarros.dir/Estado.cpp.o: ../Estado.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/joraojr/Documentos/jorao/ufjf/IA/jogo_dos_jarros/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/jogo_dos_jarros.dir/Estado.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/jogo_dos_jarros.dir/Estado.cpp.o -c /home/joraojr/Documentos/jorao/ufjf/IA/jogo_dos_jarros/Estado.cpp

CMakeFiles/jogo_dos_jarros.dir/Estado.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/jogo_dos_jarros.dir/Estado.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/joraojr/Documentos/jorao/ufjf/IA/jogo_dos_jarros/Estado.cpp > CMakeFiles/jogo_dos_jarros.dir/Estado.cpp.i

CMakeFiles/jogo_dos_jarros.dir/Estado.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/jogo_dos_jarros.dir/Estado.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/joraojr/Documentos/jorao/ufjf/IA/jogo_dos_jarros/Estado.cpp -o CMakeFiles/jogo_dos_jarros.dir/Estado.cpp.s

CMakeFiles/jogo_dos_jarros.dir/Estado.cpp.o.requires:

.PHONY : CMakeFiles/jogo_dos_jarros.dir/Estado.cpp.o.requires

CMakeFiles/jogo_dos_jarros.dir/Estado.cpp.o.provides: CMakeFiles/jogo_dos_jarros.dir/Estado.cpp.o.requires
	$(MAKE) -f CMakeFiles/jogo_dos_jarros.dir/build.make CMakeFiles/jogo_dos_jarros.dir/Estado.cpp.o.provides.build
.PHONY : CMakeFiles/jogo_dos_jarros.dir/Estado.cpp.o.provides

CMakeFiles/jogo_dos_jarros.dir/Estado.cpp.o.provides.build: CMakeFiles/jogo_dos_jarros.dir/Estado.cpp.o


CMakeFiles/jogo_dos_jarros.dir/Buscas.cpp.o: CMakeFiles/jogo_dos_jarros.dir/flags.make
CMakeFiles/jogo_dos_jarros.dir/Buscas.cpp.o: ../Buscas.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/joraojr/Documentos/jorao/ufjf/IA/jogo_dos_jarros/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/jogo_dos_jarros.dir/Buscas.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/jogo_dos_jarros.dir/Buscas.cpp.o -c /home/joraojr/Documentos/jorao/ufjf/IA/jogo_dos_jarros/Buscas.cpp

CMakeFiles/jogo_dos_jarros.dir/Buscas.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/jogo_dos_jarros.dir/Buscas.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/joraojr/Documentos/jorao/ufjf/IA/jogo_dos_jarros/Buscas.cpp > CMakeFiles/jogo_dos_jarros.dir/Buscas.cpp.i

CMakeFiles/jogo_dos_jarros.dir/Buscas.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/jogo_dos_jarros.dir/Buscas.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/joraojr/Documentos/jorao/ufjf/IA/jogo_dos_jarros/Buscas.cpp -o CMakeFiles/jogo_dos_jarros.dir/Buscas.cpp.s

CMakeFiles/jogo_dos_jarros.dir/Buscas.cpp.o.requires:

.PHONY : CMakeFiles/jogo_dos_jarros.dir/Buscas.cpp.o.requires

CMakeFiles/jogo_dos_jarros.dir/Buscas.cpp.o.provides: CMakeFiles/jogo_dos_jarros.dir/Buscas.cpp.o.requires
	$(MAKE) -f CMakeFiles/jogo_dos_jarros.dir/build.make CMakeFiles/jogo_dos_jarros.dir/Buscas.cpp.o.provides.build
.PHONY : CMakeFiles/jogo_dos_jarros.dir/Buscas.cpp.o.provides

CMakeFiles/jogo_dos_jarros.dir/Buscas.cpp.o.provides.build: CMakeFiles/jogo_dos_jarros.dir/Buscas.cpp.o


CMakeFiles/jogo_dos_jarros.dir/Pilha.cpp.o: CMakeFiles/jogo_dos_jarros.dir/flags.make
CMakeFiles/jogo_dos_jarros.dir/Pilha.cpp.o: ../Pilha.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/joraojr/Documentos/jorao/ufjf/IA/jogo_dos_jarros/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/jogo_dos_jarros.dir/Pilha.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/jogo_dos_jarros.dir/Pilha.cpp.o -c /home/joraojr/Documentos/jorao/ufjf/IA/jogo_dos_jarros/Pilha.cpp

CMakeFiles/jogo_dos_jarros.dir/Pilha.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/jogo_dos_jarros.dir/Pilha.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/joraojr/Documentos/jorao/ufjf/IA/jogo_dos_jarros/Pilha.cpp > CMakeFiles/jogo_dos_jarros.dir/Pilha.cpp.i

CMakeFiles/jogo_dos_jarros.dir/Pilha.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/jogo_dos_jarros.dir/Pilha.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/joraojr/Documentos/jorao/ufjf/IA/jogo_dos_jarros/Pilha.cpp -o CMakeFiles/jogo_dos_jarros.dir/Pilha.cpp.s

CMakeFiles/jogo_dos_jarros.dir/Pilha.cpp.o.requires:

.PHONY : CMakeFiles/jogo_dos_jarros.dir/Pilha.cpp.o.requires

CMakeFiles/jogo_dos_jarros.dir/Pilha.cpp.o.provides: CMakeFiles/jogo_dos_jarros.dir/Pilha.cpp.o.requires
	$(MAKE) -f CMakeFiles/jogo_dos_jarros.dir/build.make CMakeFiles/jogo_dos_jarros.dir/Pilha.cpp.o.provides.build
.PHONY : CMakeFiles/jogo_dos_jarros.dir/Pilha.cpp.o.provides

CMakeFiles/jogo_dos_jarros.dir/Pilha.cpp.o.provides.build: CMakeFiles/jogo_dos_jarros.dir/Pilha.cpp.o


CMakeFiles/jogo_dos_jarros.dir/Fila.cpp.o: CMakeFiles/jogo_dos_jarros.dir/flags.make
CMakeFiles/jogo_dos_jarros.dir/Fila.cpp.o: ../Fila.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/joraojr/Documentos/jorao/ufjf/IA/jogo_dos_jarros/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/jogo_dos_jarros.dir/Fila.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/jogo_dos_jarros.dir/Fila.cpp.o -c /home/joraojr/Documentos/jorao/ufjf/IA/jogo_dos_jarros/Fila.cpp

CMakeFiles/jogo_dos_jarros.dir/Fila.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/jogo_dos_jarros.dir/Fila.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/joraojr/Documentos/jorao/ufjf/IA/jogo_dos_jarros/Fila.cpp > CMakeFiles/jogo_dos_jarros.dir/Fila.cpp.i

CMakeFiles/jogo_dos_jarros.dir/Fila.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/jogo_dos_jarros.dir/Fila.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/joraojr/Documentos/jorao/ufjf/IA/jogo_dos_jarros/Fila.cpp -o CMakeFiles/jogo_dos_jarros.dir/Fila.cpp.s

CMakeFiles/jogo_dos_jarros.dir/Fila.cpp.o.requires:

.PHONY : CMakeFiles/jogo_dos_jarros.dir/Fila.cpp.o.requires

CMakeFiles/jogo_dos_jarros.dir/Fila.cpp.o.provides: CMakeFiles/jogo_dos_jarros.dir/Fila.cpp.o.requires
	$(MAKE) -f CMakeFiles/jogo_dos_jarros.dir/build.make CMakeFiles/jogo_dos_jarros.dir/Fila.cpp.o.provides.build
.PHONY : CMakeFiles/jogo_dos_jarros.dir/Fila.cpp.o.provides

CMakeFiles/jogo_dos_jarros.dir/Fila.cpp.o.provides.build: CMakeFiles/jogo_dos_jarros.dir/Fila.cpp.o


CMakeFiles/jogo_dos_jarros.dir/Lista.cpp.o: CMakeFiles/jogo_dos_jarros.dir/flags.make
CMakeFiles/jogo_dos_jarros.dir/Lista.cpp.o: ../Lista.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/joraojr/Documentos/jorao/ufjf/IA/jogo_dos_jarros/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/jogo_dos_jarros.dir/Lista.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/jogo_dos_jarros.dir/Lista.cpp.o -c /home/joraojr/Documentos/jorao/ufjf/IA/jogo_dos_jarros/Lista.cpp

CMakeFiles/jogo_dos_jarros.dir/Lista.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/jogo_dos_jarros.dir/Lista.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/joraojr/Documentos/jorao/ufjf/IA/jogo_dos_jarros/Lista.cpp > CMakeFiles/jogo_dos_jarros.dir/Lista.cpp.i

CMakeFiles/jogo_dos_jarros.dir/Lista.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/jogo_dos_jarros.dir/Lista.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/joraojr/Documentos/jorao/ufjf/IA/jogo_dos_jarros/Lista.cpp -o CMakeFiles/jogo_dos_jarros.dir/Lista.cpp.s

CMakeFiles/jogo_dos_jarros.dir/Lista.cpp.o.requires:

.PHONY : CMakeFiles/jogo_dos_jarros.dir/Lista.cpp.o.requires

CMakeFiles/jogo_dos_jarros.dir/Lista.cpp.o.provides: CMakeFiles/jogo_dos_jarros.dir/Lista.cpp.o.requires
	$(MAKE) -f CMakeFiles/jogo_dos_jarros.dir/build.make CMakeFiles/jogo_dos_jarros.dir/Lista.cpp.o.provides.build
.PHONY : CMakeFiles/jogo_dos_jarros.dir/Lista.cpp.o.provides

CMakeFiles/jogo_dos_jarros.dir/Lista.cpp.o.provides.build: CMakeFiles/jogo_dos_jarros.dir/Lista.cpp.o


# Object files for target jogo_dos_jarros
jogo_dos_jarros_OBJECTS = \
"CMakeFiles/jogo_dos_jarros.dir/main.cpp.o" \
"CMakeFiles/jogo_dos_jarros.dir/Estado.cpp.o" \
"CMakeFiles/jogo_dos_jarros.dir/Buscas.cpp.o" \
"CMakeFiles/jogo_dos_jarros.dir/Pilha.cpp.o" \
"CMakeFiles/jogo_dos_jarros.dir/Fila.cpp.o" \
"CMakeFiles/jogo_dos_jarros.dir/Lista.cpp.o"

# External object files for target jogo_dos_jarros
jogo_dos_jarros_EXTERNAL_OBJECTS =

jogo_dos_jarros: CMakeFiles/jogo_dos_jarros.dir/main.cpp.o
jogo_dos_jarros: CMakeFiles/jogo_dos_jarros.dir/Estado.cpp.o
jogo_dos_jarros: CMakeFiles/jogo_dos_jarros.dir/Buscas.cpp.o
jogo_dos_jarros: CMakeFiles/jogo_dos_jarros.dir/Pilha.cpp.o
jogo_dos_jarros: CMakeFiles/jogo_dos_jarros.dir/Fila.cpp.o
jogo_dos_jarros: CMakeFiles/jogo_dos_jarros.dir/Lista.cpp.o
jogo_dos_jarros: CMakeFiles/jogo_dos_jarros.dir/build.make
jogo_dos_jarros: CMakeFiles/jogo_dos_jarros.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/joraojr/Documentos/jorao/ufjf/IA/jogo_dos_jarros/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable jogo_dos_jarros"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/jogo_dos_jarros.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/jogo_dos_jarros.dir/build: jogo_dos_jarros

.PHONY : CMakeFiles/jogo_dos_jarros.dir/build

CMakeFiles/jogo_dos_jarros.dir/requires: CMakeFiles/jogo_dos_jarros.dir/main.cpp.o.requires
CMakeFiles/jogo_dos_jarros.dir/requires: CMakeFiles/jogo_dos_jarros.dir/Estado.cpp.o.requires
CMakeFiles/jogo_dos_jarros.dir/requires: CMakeFiles/jogo_dos_jarros.dir/Buscas.cpp.o.requires
CMakeFiles/jogo_dos_jarros.dir/requires: CMakeFiles/jogo_dos_jarros.dir/Pilha.cpp.o.requires
CMakeFiles/jogo_dos_jarros.dir/requires: CMakeFiles/jogo_dos_jarros.dir/Fila.cpp.o.requires
CMakeFiles/jogo_dos_jarros.dir/requires: CMakeFiles/jogo_dos_jarros.dir/Lista.cpp.o.requires

.PHONY : CMakeFiles/jogo_dos_jarros.dir/requires

CMakeFiles/jogo_dos_jarros.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/jogo_dos_jarros.dir/cmake_clean.cmake
.PHONY : CMakeFiles/jogo_dos_jarros.dir/clean

CMakeFiles/jogo_dos_jarros.dir/depend:
	cd /home/joraojr/Documentos/jorao/ufjf/IA/jogo_dos_jarros/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/joraojr/Documentos/jorao/ufjf/IA/jogo_dos_jarros /home/joraojr/Documentos/jorao/ufjf/IA/jogo_dos_jarros /home/joraojr/Documentos/jorao/ufjf/IA/jogo_dos_jarros/cmake-build-debug /home/joraojr/Documentos/jorao/ufjf/IA/jogo_dos_jarros/cmake-build-debug /home/joraojr/Documentos/jorao/ufjf/IA/jogo_dos_jarros/cmake-build-debug/CMakeFiles/jogo_dos_jarros.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/jogo_dos_jarros.dir/depend

