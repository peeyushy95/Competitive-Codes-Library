
//Non-self intersecting and vertices should be in clockwise or anticlockwise order """"ONLY""""""
// Area of polygon = ans/2
// Convert into double if exact area is required

long long getArea(){
    int m;
    scanf("%d",&m);
    
	vector< pair<long long,long long> > vertices;
    vertices.resize(m+1);
    
	for(int i=0;i<m;i++)
        scanf("%lld %lld",&vertices[i].first,&vertices[i].second);
    
	vertices[m].first=vertices[0].first;
    vertices[m].second = vertices[0].second;
    
	long long ans =0;
    for(int i=0;i<m;i++)
            ans+= vertices[i].first * vertices[i+1].second - vertices[i+1].first * vertices[i].second;
	

    return abs(ans);
}

