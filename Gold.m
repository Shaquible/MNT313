%reading in the text file as an array
rawData = dlmread('goldDataA.txt');
%printing the header for the table
fprintf('ID, Gold Mass [g], Sulfur Mass [Kg], Arsenic Mass [Kg], Cutoff conditions? (Y/N)\n');
%initializing an array for the output data
outputData = size(10,5);
%setting a value in the output for if the sample passes the cutoff
for i = 1:1:10
    if rawData(i,5) < 1 || rawData(i,6) > 5 || rawData (i,7) > 1
        outputData(i,5) = 'N';
    else
        outputData(i,5) = 'Y';
    end
end
%initializes an array for the values that will be used to sort the rows
sort_array = size(10);
%sets values for gold, sulfer, and arsenic mass and index number
for i = 1:1:10
   totalMass = rawData(i,2) * rawData(i,3) *rawData(i,3) * pi * rawData(i,4);
   outputData(i,1) = i; 
   outputData(i,2) = totalMass * rawData(i,5);
   sort_array(i) = outputData(i,2);
   outputData(i,3) = totalMass * rawData(i,6);
   outputData(i,4) = totalMass * rawData(i,7);
end

%gets the index for how to sort the data based on gold mass
[sort_array, index] = sort(sort_array, 'descend');
%sorts the array into a temporary array
temp = size(10,5);
for i = 1:1:10
    for j = 1:1:5
    temp(i,j) = outputData(index(i),j);
    end
end
%copys the temporary array back into the main array
outputData = temp;
%prints data to the screen
for i = 1:1:10
    fprintf('%i, ', outputData(i,1));
   for j = 2:1:4
      fprintf("%.2f, ",outputData(i,j)); 
   end
   fprintf('%c\n', outputData(i,5));
end
%prints final line indicating the max mass sample
fprintf('Max mass: %.2f g at ID %i\n', outputData(1,2), outputData(1,1));

