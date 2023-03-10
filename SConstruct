#!python
import os, subprocess

opts = Variables([], ARGUMENTS)

# Gets the standard flags CC, CCX, etc.
env = DefaultEnvironment()

# Define our options
opts.Add(EnumVariable('target', "Compilation target", 'debug', ['d', 'debug', 'r', 'release']))
opts.Add(EnumVariable('platform', "Compilation platform", '', ['', 'windows', 'x11', 'linux', 'osx']))
opts.Add(EnumVariable('p', "Compilation target, alias for 'platform'", '', ['', 'windows', 'x11', 'linux', 'osx']))
opts.Add(BoolVariable('use_llvm', "Use the LLVM / Clang compiler", 'no'))
opts.Add(PathVariable('target_path', 'The path where the lib is installed.', 'Godot/bin/'))
opts.Add(PathVariable('target_name', 'The library name.', 'gamejam', PathVariable.PathAccept))

# Local dependency paths, adapt them to your setup
godot_headers_path = 'include/godot-cpp/godot-headers/'
cpp_bindings_path = 'include/godot-cpp/'
cpp_library = 'libgodot-cpp'

# only support 64 at this time..
bits = 64

#check if bin folder in project, otherwise create it
if not os.path.exists("Godot/bin/"):
      
    # if the demo_folder directory is not present 
    # then create it.
    os.makedirs("Godot/bin/")

# Updates the environment with the option variables.
opts.Update(env)

# Process some arguments
if env['use_llvm']:
    env['CC'] = 'clang'
    env['CXX'] = 'clang++'

if env['p'] != '':
    env['platform'] = env['p']

if env['platform'] == '':
    print("No valid target platform selected.")
    quit();

# Check our platform specifics
if env['platform'] == "osx":
    env['target_path'] += 'osx/'
    cpp_library += '.osx'
    if env['target'] in ('debug', 'd'):
        env.Append(CCFLAGS = ['-g','-O2', '-arch', 'x86_64', '-std=c++17'])
        env.Append(LINKFLAGS = ['-arch', 'x86_64'])
    else:
        env.Append(CCFLAGS = ['-g','-O3', '-arch', 'x86_64', '-std=c++17'])
        env.Append(LINKFLAGS = ['-arch', 'x86_64'])

elif env['platform'] in ('x11', 'linux'):
    env['target_path'] += 'x11/'
    cpp_library += '.linux'
    if env['target'] in ('debug', 'd'):
        env.Append(CCFLAGS = ['-fPIC', '-g3','-Og', '-std=c++17'])
    else:
        env.Append(CCFLAGS = ['-fPIC', '-g','-O3', '-std=c++17'])

elif env['platform'] == "windows":
    env['target_path'] += 'win64/'
    cpp_library += '.windows'
    # This makes sure to keep the session environment variables on windows,
    # that way you can run scons in a vs 2017 prompt and it will find all the required tools
    env.Append(ENV = os.environ)

    env.Append(CCFLAGS = ['-DWIN32', '-D_WIN32', '-D_WINDOWS', '-W3', '-GR', '-D_CRT_SECURE_NO_WARNINGS', '/std:c++20'])
    if env['target'] in ('debug', 'd'):
        env.Append(CCFLAGS = ['-EHsc', '-D_DEBUG', '-MDd', '/Zi', '/Od'])
        env.Append(LINKFLAGS = ['/PDB:Godot\\bin\\win64\\Gamejam.pdb', '/DEBUG:FULL'])
    else:
        env.Append(CCFLAGS = ['-O2', '-EHsc', '-DNDEBUG', '-MD'])

if env['target'] in ('debug', 'd'):
    cpp_library += '.debug'
else:
    cpp_library += '.release'
    
    

cpp_library += '.' + str(bits)

# make sure our binding library is properly includes
env.Append(CPPPATH=[
    '.', 
    'includes/godot-cpp/godot-headers/', 
    'includes/godot-cpp/', 
    'includes/godot-cpp/include/core/', 
    'includes/godot-cpp/include/', 
    'includes/godot-cpp/include/gen/'
    ])
env.Append(LIBPATH=[
    'includes/godot-cpp/bin/'
    ])
env.Append(LIBS=[cpp_library])

# tweak this if you want to use different folders, or more folders, to store your source code in.
env.Append(CPPPATH=['Gamejam/'])
sources = Glob('Gamejam/*.cpp')

library = env.SharedLibrary(target=env['target_path'] + env['target_name'] , source=sources)

Default(library)

# Generates help for the -h scons option.
Help(opts.GenerateHelpText(env))
