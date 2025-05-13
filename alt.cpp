#include <iostream>
using namespace std;

// Global class to store and retrieve a value
class GlobalData {
public:
    GlobalData(int value) : data(value) {}
    int getData() const { return data; }
    void setData(int value) { data = value; }
private:
    int data;
};

// Function containing a local class to process GlobalData
void processData(GlobalData& gd, int multiplier) {
    // Local class to multiply the global data
    class LocalProcessor {
    public:
        LocalProcessor(int m) : multiplier(m) {}
        int process(int value) {
            return value * multiplier;
        }
    private:
        int multiplier;
    };

    LocalProcessor proc(multiplier);
    int result = proc.process(gd.getData());
    cout << "LocalProcessor result: " << result << endl;
    gd.setData(result); // Update global data with processed result
}

// Global class containing a nested class
class DataManager {
public:
    DataManager(int initial) : value(initial) {}
    
    // Nested class to analyze data
    class DataAnalyzer {
    public:
        DataAnalyzer(int v, GlobalData& g) : localValue(v), globalRef(g) {}
        void analyze() {
            cout << "Nested DataAnalyzer: Local value = " << localValue 
                 << ", Global value = " << globalRef.getData() << endl;
            if (localValue > globalRef.getData()) {
                cout << "Local value is larger than global value." << endl;
            } else {
                cout << "Global value is larger or equal to local value." << endl;
            }
        }
    private:
        int localValue;
        GlobalData& globalRef;
    };

    void createAnalyzer(GlobalData& gd) {
        DataAnalyzer analyzer(value, gd);
        analyzer.analyze();
    }
private:
    int value;
};

int main() {
    // Initialize global class
    GlobalData global(10);
    cout << "Initial GlobalData value: " << global.getData() << endl;

    // Process data using local class
    processData(global, 5); // Multiply by 5

    // Use nested class to analyze data
    DataManager manager(30);
    manager.createAnalyzer(global);

    cin.get();
    return 0;
}
