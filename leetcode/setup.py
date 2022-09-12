"""setup.py"""
import platform
import sys
from setuptools import setup, Extension

if sys.version_info >= (3, ) and platform.python_implementation() == "CPython":
    try:
        import wheel.bdist_wheel
    except ImportError:
        cmdclass = {}
    else:

        class bdist_wheel(wheel.bdist_wheel.bdist_wheel):

            def finalize_options(self):
                self.py_limited_api = f"cp3{sys.version_info[1]}"
                super().finalize_options()

        cmdclass = {"bdist_wheel": bdist_wheel}

setup(
    name="leetcode",
    version="1.0.0",
    ext_modules=[
        Extension(
            "leetcode",
            ["src/leetcode.c"],
            include_dirs=['include'],
            py_limited_api=True,
            define_macros=[("Py_LIMITED_API", None)],
        ),
    ],
    packages=["leetcode"],
    package_dir={"leetcode": "./stubs"},
    package_data={"leetcode": ["__init__.pyi", "py.typed", "max_area.pyi"]},
    cmdclass=cmdclass,
)
