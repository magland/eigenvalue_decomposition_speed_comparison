function eigtest

M=1000;
[ii,jj]=ndgrid(0:M-1,0:M-1);
X=sin(sin(ii)+sin(jj)+sin(ii+jj));
tA=tic;
[U,S]=eig(X);
fprintf('M=%d: Elapsed time (sec) = %g\n',M,toc(tA));
fprintf('First 10 eigenvalues:\n');
S=diag(S);
disp(S(1:10));

end