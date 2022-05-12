# !/bin/bash
python3 -m $1 venv-diggletters
. venv-diggletters/bin/activate
pip install scons
deactivate
cd src/
git clone https://github.com/R3mmurd/DeSiGNAR.git
cd DeSiGNAR/
make library
cd ../../