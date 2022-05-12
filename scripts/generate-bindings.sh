# !/bin/bash
cd godot-cpp
. ../venv-diggletters/bin/activate
scons platform=linux generate_bindings=yes -j4
deactivate
cd ..