plot(x,dataDelay(1,1:26),'g-o','LineWidth',1,'MarkerSize',6)
hold on
plot(x,dataDelay(2,1:26),'b--+','LineWidth',1,'MarkerSize',6)
hold on
plot(x,dataDelay(3,1:26),'r:x','LineWidth',1,'MarkerSize',6)
hold on
plot(x,dataDelay(4,1:26),'c-.d','LineWidth',1,'MarkerSize',6)
hold on
plot(x,dataDelay(5,1:26),'m-s','LineWidth',1,'MarkerSize',6)


xlabel('# of RTUs')
ylabel('Success rate within wait limit')
legend('Delayed Frame = 1','Delayed Frame = 5','Delayed Frame = 10','Delayed Frame = 15','Delayed Frame = 24')