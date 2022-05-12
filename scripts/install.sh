# !/bin/bash
python3 -m $1 venv-diggletters
. venv-diggletters/bin/activate
pip install scons
deactivate