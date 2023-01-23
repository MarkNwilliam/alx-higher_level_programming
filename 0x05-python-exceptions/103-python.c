#include <Python.h>


void print_python_list(PyObject *p)
{
    if (!PyList_Check(p))
    {
        printf("Error: Invalid PyListObject\n");
        return;
    }

    int size = PyList_Size(p);
    printf("[*] Size of the Python List = %d\n", size);
    printf("[*] Allocated = %lu\n", ((PyListObject *)p)->allocated);

    for (int i = 0; i < size; i++)
    {
        printf("Element %d: %s\n", i, Py_TYPE(PyList_GetItem(p, i))->tp_name);
    }
}

void print_python_bytes(PyObject *p)
{
    if (!PyBytes_Check(p))
    {
        printf("Error: Invalid PyBytesObject\n");
        return;
    }

    int size = PyBytes_Size(p);
    printf("[.] bytes object info\n");
    printf("  size: %d\n", size);
    printf("  trying string: %s\n", PyBytes_AsString(p));
    printf("  first %d bytes: ", size < 10 ? size : 10);
    for (int i = 0; i < size && i < 10; i++)
        printf("%02x ", (unsigned char)PyBytes_AsString(p)[i]);
    printf("\n");
}

void print_python_float(PyObject *p)
{
    if (!PyFloat_Check(p))
    {
        printf("Error: Invalid PyFloatObject\n");
        return;
    }

    double value = PyFloat_AsDouble(p);
    printf("[.] float object info\n");
    printf("  value: %g\n", value);
}
