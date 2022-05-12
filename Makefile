VENV = venv

build_lib:
	chmod +x ./scripts/buildLib.sh
	./scripts/buildLib.sh
	chmod -x ./scripts/buildLib.sh

build_cpp_bindings: install_godot_cpp
	chmod +x ./scripts/generate-bindings.sh
	./scripts/generate-bindings.sh
	chmod -x ./scripts/generate-bindings.sh
	build_IcoAdv_lib

install_godot_cpp: install_dependencies
	git submodule add -f -b 3.x https://github.com/godotengine/godot-cpp
	git submodule update --init --recursive
	cd src
	git clone https://github.com/R3mmurd/DeSiGNAR.git
	cd DeSiGNAR
	make library
	cd ..

install_dependencies:
	chmod +x ./scripts/install.sh
	./scripts/install.sh $(VENV)
	chmod -x ./scripts/install.sh

partial_clean:
	rm src/*.os

clean:
	rm -rf godot-cpp venv-diggletters